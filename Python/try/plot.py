import numpy as np
import matplotlib.pyplot as plt
import random
import logging
logging.getLogger().setLevel(logging.INFO)
global x
global end
import att_iot_client.ATT_IOT as IOT
import time

IOT.DeviceId = "2nBGwv34DG7WMmxaznPBjKtk"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"
IOT.connect(httpServer='api.allthingstalk.io', secure=False)
# evenly sampled time at 200ms intervals
t=[1,2,3,4,5,6]
def g():
    x = IOT.getAssetState(1, device=None)
    y = IOT.getAssetState(0, device=None)
    x = str(x)
    y = str(y)
    e, f = y.split(",")
    a, b = x.split(",")
    c = b.replace("}", "")
    g = f.replace("}", "")
    end2 = g.replace("u'value':", "")
    end = c.replace("u'value':", "")
    t.append(end)
    time.sleep(0.1)
    plt.plot(t)
while True:
    g()
    plt.show()

# red dashes, blue squares and green triangles

