import serial  # Serial port use korbo

ser = serial.Serial('COM7', 9600)  # COM7 port e 9600 baud rate diye connect

while True:
    print("\n1 - Buzzer ON")  # Buzzer on korar option
    print("0 - Buzzer OFF")   # Buzzer off korar option
    print("q - Quit")         # Program theke ber hobar option
    
    choice = input("Enter choice: ")  # User input nibo
    
    if choice == '1':
        ser.write(b'1')  # '1' pathabo, buzzer on hobe
    elif choice == '0':
        ser.write(b'0')  # '0' pathabo, buzzer off hobe
    elif choice.lower() == 'q':
        break  # Loop theke ber hobo

ser.close()  # Serial port bondho korbo