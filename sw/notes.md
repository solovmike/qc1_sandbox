### to connect:

```bash
ssh quad@192.168.1.70
```

### to setup vnc:
on rpi:

```bash
sudo raspi-config 

```

on lap:

```bash
sudo apt install tigervnc-viewer 
```

```bash
vncviewer
```

### setup pi3hat
from https://github.com/mjbots/pi3hat/blob/master/docs/reference.md and josh youtube video

get pi3hat_tools: https://github.com/mjbots/pi3hat/releases

### setup moteus
from https://mjbots.github.io/moteus/guides/software-installation/

install tview and moteus tool:

```bash
python -m venv --system-site-packages moteus-venv
source moteus-venv/bin/activate
pip3 install moteus moteus-pi3hat moteus-gui --ignore-installed
deactivate
```

run:

```bash 
sudo moteus-venv/bin/tview 
sudo moteus-venv/bin/moteus_tool
```

### end

pi3hat id is 32
