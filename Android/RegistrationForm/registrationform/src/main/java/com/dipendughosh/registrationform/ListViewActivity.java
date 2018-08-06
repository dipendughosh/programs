package com.dipendughosh.registrationform;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.Arrays;
import java.util.List;

public class ListViewActivity extends AppCompatActivity {

    private ListView lvProg;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_view);

        lvProg=(ListView)findViewById(R.id.lvProg);

        final String values[] = {"C","C++","JAVA","Android","C#","Assembly","Python","Ruby","VB","Scala","TCL","Shell","Seculi","HTML","JavaScript","Pearl","PHP","Swift"};

        ArrayAdapter arrayAdapter=new ArrayAdapter(this,android.R.layout.simple_list_item_1, Arrays.asList(values));

        lvProg.setAdapter(arrayAdapter);

        lvProg.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long id) {
                Toast.makeText(ListViewActivity.this,"U clicked - "+values[position],Toast.LENGTH_LONG).show();
            }
        });
    }
}
