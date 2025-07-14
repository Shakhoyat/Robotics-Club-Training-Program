import cv2
cam = cv2.VideoCapture(0)
while True:
    _, frame = cam.read()  # Camera theke frame read korchi
    frame = cv2.flip(frame, 1)  # Mirror image avoid korar jonno frame flip korchi
    cv2.imshow("Video Feed", frame)  # Frame ta display korchi
    cv2.waitKey(1)  # 1 millisecond wait korchi, jate frame refresh hoy
