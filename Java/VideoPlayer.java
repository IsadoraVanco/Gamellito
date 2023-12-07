import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.stage.Stage;

import java.io.File;

public class VideoPlayer extends Application {

    @Override
    public void start(Stage primaryStage) {
        // Caminho do arquivo de vídeo
        String videoFilePath = "caminho/do/seu/arquivo/video.mp4";

        // Criação do objeto Media com o arquivo de vídeo
        Media media = new Media(new File(videoFilePath).toURI().toString());

        // Criação do objeto MediaPlayer
        MediaPlayer mediaPlayer = new MediaPlayer(media);

        // Criação do objeto MediaView para exibir o vídeo
        MediaView mediaView = new MediaView(mediaPlayer);

        // Configuração da cena
        Scene scene = new Scene(mediaView, 640, 480);

        // Configuração do palco (Stage)
        primaryStage.setTitle("Reprodutor de Vídeo Simples");
        primaryStage.setScene(scene);

        // Exibição do palco
        primaryStage.show();

        // Inicia a reprodução do vídeo
        mediaPlayer.play();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
