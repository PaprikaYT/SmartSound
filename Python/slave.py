import logging
import serial
import  time
logging.getLogger().setLevel(logging.INFO)
import att_iot_client.ATT_IOT as IOT
global s
s = None
s = serial.Serial("/dev/ttyS0", 9600, timeout=2)
IOT.DeviceId = "c3Sup5D8N5bCVCS4pdMPzO5D"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"
IOT.connect()
IOT.addAsset(3, "humSensor", "humSensor", False, "number")
IOT.addAsset(2, "tempSensor", "tempSensor", False, "number")
IOT.subscribe()

def getint(asssetid):
    IOT.connect(httpServer='api.allthingstalk.io', secure=False)
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    b=int(b)
    return b

def getfloat(asssetid):
    IOT.connect(httpServer='api.allthingstalk.io', secure=False)
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    b=float(b)
    return b

def getstring(asssetid):
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    return b


while True:
    s.write(str(getint(0)) + "$")
    ArduinoData1 = s.readline()
    a,b=ArduinoData1.split(",")
    IOT.connect()
    IOT.send(a, 2)
    IOT.send(b, 3)