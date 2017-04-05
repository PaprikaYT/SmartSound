import Tkinter as tk
import random
import logging
logging.getLogger().setLevel(logging.INFO)
global x
import att_iot_client.ATT_IOT as IOT


IOT.DeviceId = "2nBGwv34DG7WMmxaznPBjKtk"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"

IOT.connect(httpServer='api.allthingstalk.io', secure=False)
def getnumber():
    x = IOT.getAssetState(1, device=None)
    y = IOT.getAssetState(0, device=None)
    x=str(x)
    y=str(y)
    e,f=y.split(",")
    a,b=x.split(",")
    c = b.replace("}", "")
    g=  f.replace("}","")
    end2=g.replace("u'value':","")
    end=c.replace("u'value':","")
    end ="Soundlevel:"+end+"%"
    end2="Price:"+end2+" EUR"
    timeText.configure(text=end,fg="blue")
    timeText.place(x=100,y=100)
    root.after(100, getnumber)
    label.config(text=end2,fg="red",bg="transparent")
    label.place(x=100,y=500)

root = tk.Tk()
background_image = tk.PhotoImage(file="back2.png")
background_label = tk.Label(root, image=background_image)
root.wm_title("SmartSound")
timeText = tk.Label(root, font=("Helvetica",100))
timeText.pack()
label = tk.Label(root, fg="green",font=("Helvetica",100))
background_label.place(x=0, y=0)
label.pack()
root.wm_geometry("1920x1080")

getnumber()
current = random.randint(0,50)
timeText.configure(text=current)
root.mainloop()
