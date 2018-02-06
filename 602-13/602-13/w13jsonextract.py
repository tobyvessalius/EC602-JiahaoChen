# -*- coding: utf-8 -*-
import json

a = open("puzzles.json")
b = json.loads(a)

grid = b["grid"]
size = b["size"]
lengths = b["lengths"]    