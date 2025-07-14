import serial

port1=serial.Serial('COM7', 9600)

while True:
    if port1.in_waiting > 0:
        data = port1.read().decode()
        print(data)
        
        