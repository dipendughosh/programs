from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.vflip=True
camera.start_preview()
sleep(3)
camera.capture('/home/pi/Desktop/image.jpg')
camera.stop_preview() 
