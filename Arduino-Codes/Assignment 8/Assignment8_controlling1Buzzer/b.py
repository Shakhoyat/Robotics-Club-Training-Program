import serial

ser = serial.Serial('COM7', 9600)

while True:
    print("\n1 - Buzzer ON")
    print("0 - Buzzer OFF")
    print("q - Quit")
    
    choice = input("Enter choice: ")
    
    if choice == '1':
        ser.write(b'1')  # Send '1' to turn buzzer ON
    elif choice == '0':
        ser.write(b'0')  # Send '0' to turn buzzer OFF
    elif choice.lower() == 'q':
        break

ser.close()