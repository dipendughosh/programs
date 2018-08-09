package com.dipendughosh.listviewdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    //Array of options --> ArrayAdapter --> ListView

    //ListView : {views: da_item.xml)
    private ListView listViewMain;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listViewMain = (ListView) findViewById(R.id.listViewMain);
        populateListView();
        registerClickCallback();
    }

    private void populateListView() {

        //Create list of items
        String[] myItems = {"Blue", "Green", "Purple", "Red"};
        //Build Adapter
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                this,       //Context for the activity
                R.layout.da_item,   //Layout to use(create)
                myItems);           //Items to be displayed
        //Configure thelist view
        listViewMain.setAdapter(adapter);
    }

    private void registerClickCallback() {
        listViewMain.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long id) {
                TextView textView = (TextView) view;
                String message = "You Clicked # " + position
                                + ", which is string " + textView.getText().toString();
                Toast.makeText(MainActivity.this, message, Toast.LENGTH_LONG).show();
            }
        });
    }

}
