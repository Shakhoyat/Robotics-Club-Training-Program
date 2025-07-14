import serial

se=serial.Serial('COM7', 9600)

while True:
    user_input = input("Enter data to send to Arduino: ")
    data = user_input + '\r'
    se.write(data.encode())