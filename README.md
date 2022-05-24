# Moonlander keymap

This is the keymap for my [Moonlander keyboard](https://www.zsa.io/moonlander/) based on the [QMK firmware](https://qmk.fm/).

See [docker-qmk-builder](https://github.com/fdu/docker-qmk-builder) to build QMK from a Docker container.

## Key utilization

To help create your custom layout, some scripts are provided under `scripts` to record key hits and determine utilization. First step is to record key hits by running `record.py` as root:
```
$ sudo ./record.py
all key events will now be recorded until esc is pressed
record saved to record_2022-05-24_21-00-34.log
```
A timestamped file is created with information about key hits that happened before escape was pressed. This script can be executed multiple times so that it reflects utilization in all relevant environments. Next step is to run `key_popularity.py` to show utilization per key:
```
$ ./key_popularity.py
reading record_2022-05-24_21-00-34.log...
space   1
w       1
r       1
d       1
esc     1
o       2
l       3
```
