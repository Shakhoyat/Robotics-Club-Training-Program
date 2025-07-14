import cv2  
import mediapipe as mp 
cam = cv2.VideoCapture(0)  # Camera open ...
face_mesh = mp.solutions.face_mesh.FaceMesh(refine_landmarks = True)  # FaceMesh initialize ...
while True:  
    __, frame = cam.read()  # Camera theke frame neya hoise
    frame = cv2.flip(frame, 1)  # Frame flip 
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)  # Frame ke RGB te convert ...
    output = face_mesh.process(rgb_frame)  # FaceMesh diye process 
    landmark_points = output.multi_face_landmarks  # Landmark points neya hoise
    frame_h, frame_w, _ = frame.shape  # Frame er height, width neya hoise
    if landmark_points:  # Jodi landmark thake
        landmarks = landmark_points[0].landmark  # Prothom face er landmark neya hoise
        for landmark in landmarks:  # Prottek landmark er jonno
            x = int(landmark.x * frame_w)  # X coordinate ber korlam
            y = int(landmark.y * frame_h)  # Y coordinate ber korlam
            cv2.circle(frame, (x, y), 1, (0, 255, 0))  # Frame e circle draw ...
        cv2.imshow('Face1', frame)  # Frame show 
        cv2.waitKey(1)  # 1 ms wait ...increase this to reduce load on CPU