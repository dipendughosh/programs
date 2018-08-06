package com.dipendughosh.registrationform;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.TextView;

import java.util.List;
import java.util.Map;

public class MyExpandableListAdapter extends BaseExpandableListAdapter{

    private Context context;
    private List<String> langs;
    private Map<String, List<String>> topics;

    public MyExpandableListAdapter(Context context, List<String> langs, Map<String, List<String>> topics) {
        this.context = context;
        this.langs = langs;
        this.topics = topics;
    }

    @Override
    public int getGroupCount() {
        return langs.size();
    }

    @Override
    public int getChildrenCount(int groupPosition) {
        return topics.get(langs.get(groupPosition)).size();
    }

    @Override
    public Object getGroup(int groupPosition) {
        return langs.get(groupPosition);
    }

    @Override
    public Object getChild(int groupPosition, int childPosition) {
        return topics.get(langs.get(groupPosition)).get(childPosition);
    }

    @Override
    public long getGroupId(int groupPosition) {
        return groupPosition;
    }

    @Override
    public long getChildId(int groupPosition, int childPosition) {
        return childPosition;
    }

    @Override
    public boolean hasStableIds() {
        return false;
    }

    @Override
    public View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {

        String lang=(String)getGroup(groupPosition);

        if(convertView == null){
            LayoutInflater inflater=(LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);
            convertView=inflater.inflate(R.layout.list_parent,null);
        }

        TextView tvParent=(TextView)convertView.findViewById(R.id.tvParent);
        tvParent.setText(lang);

        return convertView;
    }

    @Override
    public View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {

        String topic=(String)getChild(groupPosition,childPosition);

        if(convertView == null){
            LayoutInflater inflater=(LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);
            convertView=inflater.inflate(R.layout.list_child,null);
        }

        TextView tvChild=(TextView)convertView.findViewById(R.id.tvChild);
        tvChild.setText(topic);

        return convertView;
    }

    @Override
    public boolean isChildSelectable(int groupPosition, int childPosition) {
        return true;
    }
}
