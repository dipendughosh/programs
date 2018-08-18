package com.dipendughosh.recyclerviewfilterappbardemo;

import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class RecyclerAdapter extends RecyclerView.Adapter<RecyclerAdapter.MyViewHolder> {

    private List<String> list;

    public RecyclerAdapter(List<String> list) {
        this.list = list;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {

        TextView textView = (TextView) LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.item_view, viewGroup,false);
        MyViewHolder myViewHolder = new MyViewHolder(textView);

        return myViewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder viewHolder, int i) {
        viewHolder.VersionName.setText(list.get(i));
    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    public void updateList(List<String> newList) {
        list = new ArrayList<>();
        list.addAll(newList);
        notifyDataSetChanged();
    }

    public static class MyViewHolder extends RecyclerView.ViewHolder{

        TextView VersionName;

        public MyViewHolder(@NonNull TextView itemView) {
            super(itemView);
            VersionName = itemView;
        }
    }
}
