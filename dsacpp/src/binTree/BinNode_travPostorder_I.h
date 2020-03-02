/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����Sջ���ڵ�Ϊ���������У��ҵ�������ɼ�Ҷ�ڵ�
static void gotoLeftmostLeaf ( Stack<BinNodePosi(T)>& S ) { //��;�����ڵ�������ջ
   while ( BinNodePosi(T) x = S.top() ) //�Զ����£�������鵱ǰ�ڵ㣨��ջ����
      if ( HasLChild ( *x ) ) { //����������
         if ( HasRChild ( *x ) ) S.push ( x->rc ); //�����Һ��ӣ�������ջ
         S.push ( x->lc ); //Ȼ���ת������
      } else //ʵ������
         S.push ( x->rc ); //������
   S.pop(); //����֮ǰ������ջ���Ŀսڵ�
}

template <typename T, typename VST>
void travPost_I ( BinNodePosi(T) x, VST& visit ) { //�������ĺ�������������棩
   Stack<BinNodePosi(T)> S; //����ջ
   if ( x ) S.push ( x ); //���ڵ���ջ
   while ( !S.empty() ) { //xʼ��Ϊ��ǰ�ڵ�
      if ( S.top() != x->parent ) ////��ջ����x֮������Ϊ���֣�
         gotoLeftmostLeaf ( S ); //�����������������ҵ�HLVFL���൱�ڵݹ����룩
      x = S.pop(); visit ( x->data ); //����ջ������ǰһ�ڵ�֮��̣���������֮
   }
}