'''
Exemplo de video player 
'''
import tkinter as tk
from tkinter import filedialog
from tkinter import messagebox
from moviepy.editor import VideoFileClip
import pygame
from PIL import Image, ImageTk
import cv2

class VideoPlayer:
    def __init__(self, root):
        self.root = root
        self.root.title("Reprodutor de Vídeo com Áudio")

        self.video_frame = tk.Label(root)
        self.video_frame.pack()

        self.btn_open = tk.Button(root, text="Abrir Vídeo", command=self.open_video)
        self.btn_open.pack(pady=10)

        self.btn_play = tk.Button(root, text="Reproduzir", command=self.play_video)
        self.btn_play.pack(pady=5)

        self.btn_stop = tk.Button(root, text="Parar", command=self.stop_video)
        self.btn_stop.pack(pady=5)

        self.video_path = ""
        self.audio_path = ""

    def open_video(self):
        self.video_path = filedialog.askopenfilename(filetypes=[("Arquivos de Vídeo", "*.mp4;*.avi;*.mkv")])
        self.audio_path = self.video_path

    def play_video(self):
        if not self.video_path:
            messagebox.showinfo("Aviso", "Selecione um vídeo primeiro.")
            return

        video_clip = VideoFileClip(self.video_path)
        audio_clip = video_clip.audio

        # Inicializar o mixer do pygame para reprodução de áudio
        pygame.mixer.init()

        # Carregar o áudio do filme no pygame
        pygame.mixer.music.load(self.audio_path)

        # Definir o volume do áudio (opcional)
        pygame.mixer.music.set_volume(0.5)

        # Iniciar a reprodução do áudio
        pygame.mixer.music.play()

        cap = cv2.VideoCapture(self.video_path)

        while True:
            ret, frame = cap.read()
            if not ret:
                break

            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            img = ImageTk.PhotoImage(Image.fromarray(frame))

            self.video_frame.img = img
            self.video_frame.config(image=img)
            self.root.update_idletasks()
            self.root.update()

        # Parar a reprodução do áudio ao encerrar o vídeo
        pygame.mixer.music.stop()

        cap.release()

    def stop_video(self):
        # Parar a reprodução do áudio se o vídeo estiver sendo interrompido
        pygame.mixer.music.stop()
        messagebox.showinfo("Aviso", "Vídeo parado.")

if __name__ == "__main__":
    root = tk.Tk()
    player = VideoPlayer(root)
    root.mainloop()
