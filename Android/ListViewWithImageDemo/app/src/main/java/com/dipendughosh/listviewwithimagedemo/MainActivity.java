package com.dipendughosh.listviewwithimagedemo;

import android.content.Context;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private List<Car> myCars = new ArrayList<Car>();
    private ListView listViewCar;
    private ImageView item_imgIcon;
    private TextView item_txtMake;
    private TextView item_txtYear;
    private TextView item_txtCondition;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        populateCarList();
        populateListView();
        registerClickCallBck();
    }

    private void populateCarList() {

        myCars.add(new Car("Ford", 1940, R.drawable.ic_menu_alarm, "Needing Work"));
        myCars.add(new Car("Toyota", 1994, R.drawable.ic_menu_amazon, "Lovable"));
        myCars.add(new Car("Honda", 1947, R.drawable.ic_menu_add, "Wet"));
        myCars.add(new Car("Tesla", 1987, R.drawable.ic_menu_backup, "Dry"));
        myCars.add(new Car("Jeep", 1900, R.drawable.ic_menu_brush, "Cold"));

    }

    private void populateListView() {

        ArrayAdapter<Car> adapter = new MyListAdapter();
        listViewCar = (ListView) findViewById(R.id.listViewCar);
        listViewCar.setAdapter(adapter);
    }

    private void registerClickCallBck() {

        ListView list = (ListView) findViewById(R.id.listViewCar);
        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long id) {
                Car clickedCar = myCars.get(position);

                String message = "You clicked postion #" + position
                                + " which is car make " + clickedCar.getMake();
                Toast.makeText(MainActivity.this, message, Toast.LENGTH_LONG).show();
            }
        });
    }

    private class MyListAdapter extends ArrayAdapter<Car> {

        public MyListAdapter() {
            super(MainActivity.this, R.layout.item_view, myCars);
        }

        @NonNull
        @Override
        public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {

            //Make sure we have a view to work with
            View itemView = convertView;

            if(itemView == null) {
                itemView = getLayoutInflater().inflate(R.layout.item_view, parent, false);
            }

            //Find the car to work with
            Car currentCar = myCars.get(position);

            //Fill view
            item_imgIcon = (ImageView)itemView.findViewById(R.id.item_imgIcon);
            item_imgIcon.setImageResource(currentCar.getIconID());
            item_txtMake = (TextView)itemView.findViewById(R.id.item_txtMake);
            item_txtMake.setText(currentCar.getMake());
            item_txtYear = (TextView)itemView.findViewById(R.id.item_txtYear);
            item_txtYear.setText("" + currentCar.getYear());
            item_txtCondition = (TextView)itemView.findViewById(R.id.item_txtCondition);
            item_txtCondition.setText(currentCar.getCondition());

            return itemView;
        }
    }
}
