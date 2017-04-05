from Tkinter import *
import random
import logging
logging.getLogger().setLevel(logging.INFO)
global x
global end
import att_iot_client.ATT_IOT as IOT


IOT.DeviceId = "2nBGwv34DG7WMmxaznPBjKtk"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"
breite=1920
hoehe=1080
IOT.connect(httpServer='api.allthingstalk.io', secure=False)
master = Tk()
master.attributes("-fullscreen", True)
def getnumber():
    w.delete("all")
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
    end = "Soundlevel:" + end + "%"
    end2 = "Price:" + end2 + " EUR"
    w.create_image(breite, 0, anchor=NE, image=filename)
    w.create_text(breite/2, hoehe*0.3, text=end, fill="#ff471a", font=('Ubuntu', '100', 'bold'))
    w.create_text(breite/2,hoehe*0.6,text=end2,fill="grey",font=("Ubuntu", 130))
    master.after(300, getnumber)


def callback(event):
    master.attributes("-fullscreen", False)

master.bind("<Key>", callback)
w = Canvas(master, width=breite, height=hoehe)
w.pack()
filename = PhotoImage(file = "back4.png")
getnumber()
mainloop()
#w.create_line(0, 0, 200, 100)
#w.create_line(0, 100, 200, 0, fill="red", dash=(4, 4))
#w.create_rectangle(50, 25, 150, 75, fill="blue")