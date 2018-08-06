package com.dipendughosh.registrationform;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ExpandableListAdapter;
import android.widget.ExpandableListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ExpandableListViewActivity extends AppCompatActivity {

    private ExpandableListView expandableListView;
    private List<String> langs;
    private Map<String, List<String>> topics;
    private ExpandableListAdapter listAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_expandable_list_view);

        expandableListView=(ExpandableListView)findViewById(R.id.expandableListView);
        fillData();

        listAdapter=new MyExpandableListAdapter(this,langs,topics);

        expandableListView.setAdapter(listAdapter);

        expandableListView.setOnChildClickListener(new ExpandableListView.OnChildClickListener() {
            @Override
            public boolean onChildClick(ExpandableListView expandableListView, View view, int groupPosition, int childPosition, long id) {

                Toast.makeText(ExpandableListViewActivity.this,langs.get(groupPosition)+" : "+topics.get(langs.get(groupPosition)).get(childPosition),Toast.LENGTH_LONG).show();
                return false;
            }
        });
    }

    public void fillData(){
        langs=new ArrayList<>();
        topics=new HashMap<>();

        langs.add("Java");
        langs.add("C");

        List<String> java=new ArrayList<>();
        List<String> c=new ArrayList<>();

        java.add("Super");
        java.add("Encapsulation");
        java.add("Methods");

        c.add("Procedure");
        c.add("Pointers");
        c.add("Array");

        topics.put(langs.get(0),java);
        topics.put(langs.get(1),c);
    }
}
