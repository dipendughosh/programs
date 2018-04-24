from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
for i in range(4):
    camera.start_recording('/home/pi/USB/video%s.h264' % i)
    sleep(10)
    camera.stop_recording()
camera.stop_preview()
