import serial  # Serial library import korlam

ser = serial.Serial('COM7', 9600)  # COM7 port e 9600 baud rate diye serial connection korlam
while True:  # Infinite loop cholbe
    line = ser.readline().decode().strip()  # Serial theke ekta line read kore decode & strip korlam
    if line:  # Jodi line empty na hoy
        print(line)  # Line ta print korlam
