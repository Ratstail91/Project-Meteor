/* File Name: llist.cpp
 * Author: Kayne Ruse
 * Date: 16/4/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Project RPG.
 * 
 * Project RPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Project RPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Project RPG.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     This is a simple single linked list, works as a stack.
 *     There is no need for optimisation yet.
 *     This works with pointers.
 *     
 *     WARNING! The name of this class is currently a misnomer.
 *     This "LList" class needs to be renamed "LStack" since it acts as a stack.
*/
#ifndef KR_LLIST_CPP_ //template quirk
#define KR_LLIST_CPP_ 20120416

#include "llist.h"

//-------------------------
//Public access members
//-------------------------

template<typename T>
LList<T>::LList() {
	m_pHead = NULL;
}

template<typename T>
LList<T>::~LList() {
	//cleanup the pointers
	while (m_pHead != NULL) {
		delete Pop();
	}
}

template<typename T>
T* LList<T>::Push(T* p) {
	LLNode<T>* n = new LLNode<T>();

	//push onto the stack
	n->m_pData = p;
	n->m_pNext = m_pHead;
	m_pHead = n;

	return p;
}

template<typename T>
T* LList<T>::Pop() {
	LLNode<T>* n = m_pHead;

	if (n == NULL) return NULL;

	//pop from the stack
	T* p = n->m_pData;
	m_pHead = n->m_pNext;
	delete n;

	return p;
}

template<typename T>
LLNode<T>* LList<T>::Head() {
	return m_pHead;
}

#endif
