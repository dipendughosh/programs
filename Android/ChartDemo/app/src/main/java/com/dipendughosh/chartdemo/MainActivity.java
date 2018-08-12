package com.dipendughosh.chartdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.github.mikephil.charting.charts.PieChart;
import com.github.mikephil.charting.data.PieData;
import com.github.mikephil.charting.data.PieDataSet;
import com.github.mikephil.charting.data.PieEntry;
import com.github.mikephil.charting.utils.ColorTemplate;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    float rainFall[] = {1f, 2f, 3f, 4f, 5f, 6f, 7f, 88f, 9f, 10f, 11f, 12f};
    String month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupPieChart();
    }

    private void setupPieChart() {
        //populating a list of pie entires

        List<PieEntry> pieEntries = new ArrayList<>();
        for (int i = 0; i < rainFall.length; i++) {
            pieEntries.add(new PieEntry(rainFall[i], month[i]));
        }

        PieDataSet dataSet = new PieDataSet(pieEntries, "Raindall for City");
        dataSet.setColors(ColorTemplate.COLORFUL_COLORS);
        PieData data = new PieData(dataSet);

        //get the chart

        PieChart chart = (PieChart) findViewById(R.id.chart);
        chart.setData(data);
        chart.animateY(1000);
        chart.invalidate();
    }
}
