from flask import Flask, jsonify, request, render_template
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
#    return "<h1>Temlate</h1>"
#    if app.debug:
#       return requests.get('http://localhost:8080/{}'.format(path)).text
    return render_template("index.html")




#@app.route('/')
#def hello():
#    return "<h1>Hellooooo ept</h3>"



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
                'sensors': []
            }
            for sensor in device.sensors:
                obj['sensors'].append({'id': sensor.id, 'name': sensor.name})
            results.append(obj)
        response = jsonify(results)
        response.status_code = 200
        return response
    else:
        return "error"

@app.route('/api/sendData', methods=['POST'])
def getDataInOrange():
    data = json.loads(request.data.decode('utf-8'))
    if len(data) > 0:
        sensor_data = models.Data()
        #device_id = 1 = data['device_id']
        print(data)
        for sensor in data["sensors"]:
            print(sensor)
            sensor_data.device_id = 1
            sensor_data.sensor_id = sensor['id']
            sensor_data.data = sensor['data'];
            sensor_data.save()
        return "Server"
    return "none"

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

if __name__=="__main__":
    app.run(host='0.0.0.0',port=5000, debug=True)
