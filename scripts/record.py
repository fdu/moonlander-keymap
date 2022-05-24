#!/usr/bin/env python3

import keyboard
from datetime import datetime

print("all key events will now be recorded until esc is pressed")
recorded = keyboard.record(until='esc')
filename = "record_" + datetime.now().strftime("%Y-%m-%d_%H-%M-%S") + ".log"
file = open(filename, "w")
for key in recorded:
  file.write("%s\n" % key.to_json())
file.close()
print("record saved to %s" % filename)