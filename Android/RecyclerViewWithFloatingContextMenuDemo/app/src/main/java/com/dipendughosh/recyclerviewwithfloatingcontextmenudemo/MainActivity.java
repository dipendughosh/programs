package com.dipendughosh.recyclerviewwithfloatingcontextmenudemo;

import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.MenuItem;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private int[] fruit_id = {R.drawable.ic_menu_1,
            R.drawable.ic_menu_2,
            R.drawable.ic_menu_3,
            R.drawable.ic_menu_4,
            R.drawable.ic_menu_5,
            R.drawable.ic_menu_6,
            R.drawable.ic_menu_7,
            R.drawable.ic_menu_8,
            R.drawable.ic_menu_9,
            R.drawable.ic_menu_10};
    private String[] fruits_name;
    private List<Fruit> fruits = new ArrayList<>();
    private RecyclerView recyclerView;
    private RecylerAdapter adapter;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fruits_name = getResources().getStringArray(R.array.fruit_names);
        recyclerView = findViewById(R.id.mRecyclerview);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        recyclerView.setHasFixedSize(true);

        getFruits();

        adapter = new RecylerAdapter(fruits);
        recyclerView.setAdapter(adapter);
    }

    private void getFruits() {
        int count = 0;

        for (String fruitName : fruits_name){
            Fruit fruit = new Fruit(fruit_id[count], fruitName);
            fruits.add(fruit);
        }
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {

        switch (item.getItemId()) {
            case 121:
                adapter.removeItem(item.getGroupId());
                displayMessage("deleted");
                return true;
            case 122:
                displayMessage("added");
                return true;
            default:
                return super.onContextItemSelected(item);
        }

    }

    private void displayMessage(String message) {
        Snackbar.make(findViewById(R.id.rootView), message, Snackbar.LENGTH_LONG).show();
    }
}
