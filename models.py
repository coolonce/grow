from flask import Flask
from flask_sqlalchemy import SQLAlchemy

db = SQLAlchemy()


sensorInDevice = db.Table('sensor_in_device',
                          db.Column('device_id', db.Integer, db.ForeignKey('devices.id'), primary_key=True),
                          db.Column('sensor_id', db.Integer, db.ForeignKey('sensors.id'), primary_key=True)
                          )
sensor_date = db.Table('sensor_data',
                       db.Column('device_id', db.Integer, db.ForeignKey('devices.id')),
                       db.Column('sensor_id', db.Integer, db.ForeignKey('sensors.id'))
                       )


class Device(db.Model):
    __tablename__= 'devices'
    id = db.Column(db.Integer, primary_key=True)
    name_owner = db.Column(db.String(45))
    address = db.Column(db.String(45))
    version_po = db.Column(db.String(45))
    comment = db.Column(db.String(45))
    date_buy = db.Column(db.String(45))
    sensors = db.relationship('Sensor', secondary=sensorInDevice, lazy='subquery',
                              backref=db.backref('devices', lazy=True))

#    def __init__(self, name):
#        self.name = name

    def save(self):
        db.session.add(self)
        db.session.commit()
    @staticmethod
    def get(id):
        return Device.query.filter_by(id=id).first()
    @staticmethod
    def get_all():
        return Device.query.all()

    def delete(self):
        db.session.delete(self)
        db.session.commit()

    def __repr__(self):
        return "deviceList: {}".format(self.name)

class Sensor(db.Model):
    __tablename__ = 'sensors'

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(255))

    def __init__(self, name):
        self.name = name

    def  save(self):
        db.session.add(self)
        db.session.commit()

    @staticmethod
    def get_all():
        return Sensor.query.all()

    @staticmethod
    def get(id):
        return Sensor.query.filter_by(id=id).first()

    def delete(self):
        db.session.delete(self)
        db.session.commit()

    def __rept__(self):
        return "sensors list: {}".format(self.name)
from sqlalchemy import desc;
class Data(db.Model):

    __tablename__ = 'sensor_data'
    __table_args__ = {'extend_existing': True}

    id = db.Column(db.Integer, primary_key=True)
    device_id = db.Column(db.Integer)
    sensor_id = db.Column(db.Integer)
    data = db.Column(db.Float)
    date_add = db.Column(db.DateTime)

#    def __init__(self):
 #       return self

#    @staticmethod
    def save(self):
        db.session.add(self)
        db.session.commit()
    @staticmethod
    def get_all():
        return Data.query.all();

    @staticmethod
    def get_sensor_data(device_id, sensor_id):
        data = Data.query.filter_by(device_id=device_id, sensor_id=sensor_id).all()
        return data

    @staticmethod
    def get_sensor_data_end(device_id, sensor_id):
        data = Data.query.filter_by(device_id=device_id, sensor_id=sensor_id).order_by(desc(Data.date_add)).limit(1)
        return data
