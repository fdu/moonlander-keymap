#!/usr/bin/env python3

import sys
import json
import glob

hits = {}
for filename in glob.glob("record_*.log"):
  print("reading %s..." % filename)
  file = open(filename, "r")
  for line in file:
    data = json.loads(line)
    if data["event_type"] == "down":
      if data["name"] in hits:
        hits[data["name"]] = hits[data["name"]] + 1
      else:
        hits[data["name"]] = 1
  file.close()
sortedHits = sorted(hits.items(), key=lambda x: x[1])
for hit in sortedHits:
  print("%s\t%s" % (hit[1], hit[0]))
