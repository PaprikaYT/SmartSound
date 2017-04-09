import Tkinter
import logging
logging.getLogger().setLevel(logging.INFO)
import att_iot_client.ATT_IOT as IOT
IOT.DeviceId = "2nBGwv34DG7WMmxaznPBjKtk"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"
IOT.connect(httpServer='api.allthingstalk.io', secure=False)

class SimplePlot(Tkinter.Canvas):

    def plot(self, x, y):
        self.create_line((x, y, x+1, y), fill="black")

import random, time


root = Tkinter.Tk()
root.title("demoSimplePlot")

widget = SimplePlot(root)
widget.pack(fill="both", expand=1)

widget.update() # display the widget
cnt = 0
data = []
while True:
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
    data.append(int(end))
    cnt = cnt + 1
    widget.plot(cnt,int(end))
    widget.update()
    if (cnt > 1000):
        cnt=0

print time.time() - t0, "seconds"

root.mainloop()