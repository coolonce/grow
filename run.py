from flask import Flask, jsonify, request, render_template, send_file
from random import *
from flask_cors import CORS
import requests
import json
import models

app = Flask(__name__,
            static_folder="./dist/static",
            template_folder="./dist",
            instance_relative_config=True)

app.config['SQLALCHEMY_DATABASE_URI'] = "mysql://root:root@localhost/grow"
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

cors = CORS(app, resources={r"/api/*": {"origins": "*"}})

models.db.init_app(app)

@app.route('/',defaults={'path': ''})
@app.route('/<path:path>')
def catch_all(path):
    return render_template("index.html")

@app.route('/api/addip/<string:ip>',  methods=['GET'])
def SaveIpDevice(ip):
    with open('ips.txt', 'a') as ips_file:
        ips_file.write(ip+"\r\n")
        ips_file.close()
    return jsonify({'message': True})

@app.route('/api/latest')
def getLatestPo():
    return send_file('main.ino')

@app.route('/api/random')
def random_number():
    response = {
        'randomNumber': randint(1, 100)
    }
    return jsonify(response)

@app.route('/api/update-sensors',  methods=['POST'])
def updateSensors():
    f = open('settings.txt', 'w+')
    data = json.loads(request.data.decode('utf-8'))
    keys = data.keys
    print(type(keys))
    for key, val in data.items():
        print(key)
        sett = key+":"+str(val)+"\r\n"
        f.write(sett)
    return "www"


@app.route('/api/device', methods=['POST', 'GET'])
def devices():
    if request.method == "GET":
        devices = models.Device.get_all()
        results = []
        for device in devices:
            obj = {
                'id': device.id,
                'name_owner': device.name_owner,
                'date_buy': device.date_buy,
                'version': device.version_po,
                'comment': device.comment,
                'sensors': []
            }
            for sensor in device.sensors:
                obj['sensors'].append({'id': sensor.id, 'name': sensor.name})
            results.append(obj)
        response = jsonify(results)
        response.status_code = 200
        return response
    else:
        device = models.Device()
        device.name_owner = 'newCreate'
        device.version_po = '0.0001'
        device.save()
        return jsonify({'message':'create Device', 'id': device.id, 'version': '0.0001'})

@app.route('/api/device/<int:device_id>', methods=['POST'])
def deviceUpdate(device_id):
    if(not device_id == 0 and request.method == "POST"):
        data = json.loads(request.data.decode('utf-8'))
        device = models.Device().get(device_id)
        if('comment' in data and not data['comment'] == ''):
            device.comment = data['comment']
        if('name' in data and not data['name'] == ''):
            device.name_owner = data['name']
        device.save()
        return jsonify({'message':'update', 'code': 200})
    else:
        return jsonify({'message':'error update', 'code': 500})

@app.route('/api/device/checkver/<int:device_id>', methods=['GET'])
def checkVerPo(device_id):
    device = models.Device.get(device_id)
    obj = {
        'ver': device.version_po
    }
    return jsonify(obj)


@app.route('/api/sendData', methods=['POST'])
def getDataInOrange():
    data = json.loads(request.data.decode('utf-8'))
    if len(data) > 0:        
        device_id = data['device_id']
        print(data)
        for sensor in data["sensors"]:
            print(sensor)
            sensor_data = models.Data()
            sensor_data.device_id = device_id
            sensor_data.sensor_id = sensor['id']
            sensor_data.data = sensor['data'];
            sensor_data.save()
        return jsonify({'message':'data send', 'code': 200})
    return jsonify({'message':'dont send data', 'code': 500})

@app.route('/api/sensor', methods=['POST', 'GET'])
def sensors():
    if request.method == "GET":
        sensors = models.Sensor.get_all()
        results = []
        for sensor in sensors:
            obj = {
                'id': sensor.id,
                'name': sensor.name
            }
            results.append(obj)
        response = jsonify(results)
        response.status_code = 200
        return response
    else:
        return "error"

@app.route('/api/sensor/<int:sensor_id>')
def getSensorsinDevice(sensor_id):
    sensor = models.Sensor.get(sensor_id)
    obj ={
        'id': sensor.id,
        'name': sensor.name
    }
    return jsonify(obj)


@app.route('/api/data/<int:device_id>/<int:sensor_id>')
def getData(device_id, sensor_id):
    data = models.Data.get_sensor_data_end(device_id, sensor_id)
    results = []
    for item in data:
        obj = {
            'id': item.id,
            'data': item.data,
            'date_add': item.date_add
        }
        results.append(obj)
    return jsonify(results)

@app.route('/api/data_all/<int:device_id>/<int:sensor_id>')
def getDataAll(device_id, sensor_id):
    data = models.Data.get_sensor_data(device_id, sensor_id)
    results = []
    for item in data:
        obj = {
            'id': item.id,
            'data': item.data,
            'date_add': item.date_add
        }
        results.append(obj)
    return jsonify(results)

@app.route('/api/settings/<int:device_id>/<int:sensor_id>', methods=['POST', 'GET'])
def changeSettings(device_id, sensor_id):
    if request.method == "GET" and not device_id == 0 and not sensor_id == 0:
        set = models.Settings.get(device_id, sensor_id)
        print(set)
        obj = {
              'settings': set.settings
         }
        return jsonify(obj)
    elif request.method == "POST" and not device_id == 0 and not sensor_id == 0:
        set = models.Settings.get(device_id, sensor_id)
        data = json.loads(request.data.decode('utf-8'))
        if len(data) > 0:
            set.settings = data['settings']
            set.save()
            return jsonify({'message': 'ok', 'status': 200})
        else:
            return jsonify({'message': 'bad data', 'status': 500})
    else:
        return jsonify({'message': 'bad request', 'status': 500})

if __name__=="__main__":
    app.run(host='0.0.0.0',port=5000, debug=True)
