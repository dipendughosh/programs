package com.dipendughosh.browsegalleryimage;

import android.content.Context;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Button btnPrevious;
    private Button btnNext;
    private ImageView imageView;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        scanStorage();
    }

    private void scanStorage() {

        Log.d("Files", "1. Path: " + MainActivity.this.getFilesDir());
        File extStorageDir=new File("/");
        Log.d("Files", "2. Path: " + extStorageDir.list());
        String[] fileList=extStorageDir.list();
        Log.d("Files", "3. Path: " + fileList);

        /*for(String fileName:fileList)
            System.out.println("FileName="+fileName);*/

    }
}
