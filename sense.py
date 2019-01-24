#!/usr/bin/env python
import os
import time
import serial
seri =serial.Serial("/dev/ttyACM0", 9600)
seri.flushInput()
sys_show = 'pgrep feh'
 
sys_kill = 'kill ' 
light = 1
light2 = 1

os.system('script_slideshow.sh')

while True:
	reading = seri.read(1)
	seri.flushInput()
	print (reading)
	if reading[0] =="1":
		light = 1
		reading = 0
		print('n1')
	elif reading[0] == "2":
		light = 0
		reading = 0
		print('n2')
	elif reading[0] == "3":
		light = 1
		reading = 0
		print('n3')
	elif reading[0] == "4":
		light = 0
		reading = 0
		print('n4')
	if light2 != light:
		print('notmatch')
		light2 = light  
		if light2 == 1:
			print ('dog')
			result = os.popen(sys_show).read()
			os.system('script_slideshow.sh')
			time.sleep(2)
			os.system(sys_kill+result)
		else :
			print ('cat')
			result = os.popen(sys_show).read()
			os.system('script_slideshow2.sh')
			time.sleep(2)
			os.system(sys_kill+result)
	
