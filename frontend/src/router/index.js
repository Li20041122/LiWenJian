import { createRouter, createWebHistory } from 'vue-router'
import BookList from '../views/BookList.vue'
import UserList from '../views/UserList.vue'
import BorrowList from '../views/BorrowList.vue'
import DepartList from '../views/DepartList.vue'

const routes = [
  {
    path: '/',
    redirect: '/books'
  },
  {
    path: '/books',
    name: 'BookList',
    component: BookList
  },
  {
    path: '/users',
    name: 'UserList',
    component: UserList
  },
  {
    path: '/borrows',
    name: 'BorrowList',
    component: BorrowList
  },
  {
    path: '/departs',
    name: 'DepartList',
    component: DepartList
  }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
