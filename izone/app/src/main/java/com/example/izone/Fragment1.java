package com.example.izone;

import androidx.fragment.app.Fragment;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import androidx.annotation.Nullable;

public class Fragment1 extends Fragment{
    private View view;
    private Button btnP, btnS;
    MediaPlayer mediaPlayer;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, Bundle savedInstanceState) {
        view = inflater.inflate(R.layout.fragment1, container, false);

        // 라비앙로즈
        btnP = view.findViewById(R.id.btn1_play);
        btnS = view.findViewById(R.id.btn1_stop);
        btnP.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(mediaPlayer != null) {
                    mediaPlayer.stop();
                    mediaPlayer = null;
                }
                mediaPlayer = MediaPlayer.create(getActivity(), R.raw.iz_1);
                mediaPlayer.start();
            }
        });

        btnS.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(mediaPlayer != null) {
                    mediaPlayer.stop();
                    mediaPlayer.reset();
                }
            }
        });

        return view;
    }


}
