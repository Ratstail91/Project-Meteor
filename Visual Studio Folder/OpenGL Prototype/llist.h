/* File Name: llist.h
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
#ifndef KR_LLIST_H_
#define KR_LLIST_H_ 20120416

template<typename T>
struct LLNode {
	T* m_pData;
	LLNode* m_pNext;
};

template<typename T>
class LList {
public:
	/* Internal type declarations */
	typedef LLNode<T>* iterator;

	/* Public access members */
	LList();
	~LList();

	T* Push(T*);
	T* Pop();

	LLNode<T>* Head();

private:
	/* Private access members */
	LLNode<T>* m_pHead;
};

//template quirk
#include "llist.cpp"

#endif
