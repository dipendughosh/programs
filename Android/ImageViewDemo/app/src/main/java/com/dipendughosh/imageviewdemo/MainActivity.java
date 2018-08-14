package com.dipendughosh.imageviewdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private static ImageView imgView;
    private static Button buttonSbm;

    private SeekBar seekBar;
    private TextView textView;
    private int current_image_index;
    int[] images = {R.drawable.ic_menu_achievement,R.drawable.ic_menu_add,R.drawable.ic_menu_alarm};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        buttonClick();
    }

    public  void buttonClick() {
        imgView = (ImageView)findViewById(R.id.imageView);
        buttonSbm =(Button)findViewById(R.id.button);
        buttonSbm.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        current_image_index++;
                        current_image_index = current_image_index % images.length;
                        imgView.setImageResource(images[current_image_index]);
                        //imgView.setImageResource(R.drawable.and_image2);
                    }
                }
        );
    }
}
