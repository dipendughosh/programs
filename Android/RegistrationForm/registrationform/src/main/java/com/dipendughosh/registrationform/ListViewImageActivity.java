package com.dipendughosh.registrationform;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class ListViewImageActivity extends AppCompatActivity {

    private ListView lvProg;
    private Context context;
    ArrayList progList;

    public static Integer [] progImages={
        R.drawable.one,R.drawable.two,R.drawable.three,R.drawable.four,R.drawable.five,
        R.drawable.one,R.drawable.two,R.drawable.three,R.drawable.four,R.drawable.five,
        R.drawable.one,R.drawable.two,R.drawable.three,R.drawable.four,R.drawable.five,
        R.drawable.one,R.drawable.two,R.drawable.three
    };

    public static String[] progNames={
        "C","C++","JAVA","Android","C#","Assembly","Python","Ruby","VB","Scala","TCL","Shell","Seculi","HTML","JavaScript","Pearl","PHP","Swift"
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_view_image);

        MyListImageAdapter myAdapter=new MyListImageAdapter(this,progNames,progImages);

        lvProg=(ListView) findViewById(R.id.lvProg);

        lvProg.setAdapter(myAdapter);

        lvProg.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Toast.makeText(ListViewImageActivity.this,"u clicked at "+progNames[i],Toast.LENGTH_LONG).show();
            }
        });
    }
}
