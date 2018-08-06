package com.dipendughosh.registrationform;

import android.app.Activity;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.dipendughosh.registrationform.R;

public class MyListImageAdapter extends ArrayAdapter<String>{

    private final Activity context;
    private final String[] progNames;
    private final Integer[] progImages;

    public MyListImageAdapter(Activity context, String[] progNames, Integer[] progImages) {
        super(context, R.layout.activity_image_list,progNames);
        this.context = context;
        this.progNames = progNames;
        this.progImages = progImages;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        LayoutInflater inflater=context.getLayoutInflater();
        View rowView=inflater.inflate(R.layout.activity_image_list,null,true);
        TextView tvTitle=(TextView)rowView.findViewById(R.id.tvName);
        ImageView ivImage=(ImageView)rowView.findViewById(R.id.ivImage);

        tvTitle.setText(progNames[position]);
        ivImage.setImageResource(progImages[position]);

        return rowView;
    }
}
