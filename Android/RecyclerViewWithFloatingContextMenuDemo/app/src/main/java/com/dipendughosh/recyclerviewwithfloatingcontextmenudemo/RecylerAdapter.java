package com.dipendughosh.recyclerviewwithfloatingcontextmenudemo;

import android.content.Context;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.widget.CardView;
import android.support.v7.widget.RecyclerView;
import android.view.ContextMenu;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class RecylerAdapter extends RecyclerView.Adapter<RecylerAdapter.MyViewHolder> {

    private List<Fruit> fruits = new ArrayList<>();
   // private Context context;

    public RecylerAdapter(List<Fruit> fruits){//}, Context context) {
        this.fruits = fruits;
        //this.context = context;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.item_layout, viewGroup,false);
        //ImageViewHolder imageViewHolder = new ImageViewHolder(view, context, images);
        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder viewHolder, int i) {
        //int image_id = fruits[i];
        viewHolder.FruitImage.setImageResource(fruits.get(i).getFruit_imaage_id());
        viewHolder.FruitName.setText(fruits.get(i).getFruit_name());
    }

    @Override
    public int getItemCount() {

        return fruits.size();
    }

    public static class MyViewHolder extends RecyclerView.ViewHolder implements View.OnCreateContextMenuListener{//} implements View.OnClickListener{

        ImageView FruitImage;
        TextView FruitName;
        CardView CardView;
        //Context context;
        //int [] images;

        public MyViewHolder(@NonNull View itemView){//}, Context context, int[] images) {
            super(itemView);
            FruitImage = itemView.findViewById(R.id.fruit_album);
            FruitName = itemView.findViewById(R.id.fruit_name);
            CardView = itemView.findViewById(R.id.mCardView);
            CardView.setOnCreateContextMenuListener(this);
            //itemView.setOnClickListener(this);
            //this.context = context;
            //this.images = images;
        }

        @Override
        public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
            menu.setHeaderTitle("Select item");
            menu.add(this.getAdapterPosition(),121,0,"Delete this item");
            menu.add(this.getAdapterPosition(), 122, 1, "Add to wish list");
        }


        /*@Override
        public void onClick(View v) {

            Intent intent = new Intent(context, DisplayActivity.class);
            intent.putExtra("image_id", images[getAdapterPosition()]);

            context.startActivity(intent);
        }*/
    }


    public void removeItem(int position) {
        fruits.remove(position);
        notifyDataSetChanged();
    }
}
