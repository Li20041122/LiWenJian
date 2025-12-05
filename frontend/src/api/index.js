import axios from 'axios'

const api = axios.create({
  baseURL: '/api',
  timeout: 5000
})

// 图书API
export const bookApi = {
  getAll: () => api.get('/book'),
  getById: (id) => api.get(`/book/${id}`),
  create: (data) => api.post('/book', data),
  update: (id, data) => api.put(`/book/${id}`, data),
  delete: (id) => api.delete(`/book/${id}`)
}

// 用户API
export const userApi = {
  getAll: () => api.get('/user'),
  getById: (id) => api.get(`/user/${id}`),
  create: (data) => api.post('/user', data),
  update: (id, data) => api.put(`/user/${id}`, data),
  delete: (id) => api.delete(`/user/${id}`)
}

// 借阅API
export const borrowApi = {
  getAll: () => api.get('/borrow'),
  getByKey: (userid, bookid) => api.get(`/borrow/${userid}/${bookid}`),
  create: (data) => api.post('/borrow', data),
  update: (userid, bookid, data) => api.put(`/borrow/${userid}/${bookid}`, data),
  delete: (userid, bookid) => api.delete(`/borrow/${userid}/${bookid}`)
}

// 部门API
export const departApi = {
  getAll: () => api.get('/depart'),
  getById: (id) => api.get(`/depart/${id}`),
  create: (data) => api.post('/depart', data),
  update: (id, data) => api.put(`/depart/${id}`, data),
  delete: (id) => api.delete(`/depart/${id}`)
}

export default api
