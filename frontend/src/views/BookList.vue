<template>
  <div class="book-list">
    <h2>图书管理</h2>
    <el-button type="primary" @click="showAddDialog">添加图书</el-button>

    <el-table :data="books" style="width: 100%; margin-top: 20px" border>
      <el-table-column prop="bookid" label="图书ID" width="120" />
      <el-table-column prop="bookname" label="书名" width="200" />
      <el-table-column prop="authors" label="作者" width="150" />
      <el-table-column prop="publication" label="出版社" width="180" />
      <el-table-column prop="publicdate" label="出版日期" width="120" />
      <el-table-column prop="price" label="价格" width="100" />
      <el-table-column label="操作" width="180">
        <template #default="{ row }">
          <el-button size="small" @click="editBook(row)">编辑</el-button>
          <el-button size="small" type="danger" @click="deleteBook(row.bookid)">删除</el-button>
        </template>
      </el-table-column>
    </el-table>

    <el-dialog v-model="dialogVisible" :title="dialogTitle" width="500px">
      <el-form :model="form" label-width="100px">
        <el-form-item label="图书ID">
          <el-input v-model="form.bookid" :disabled="isEdit" />
        </el-form-item>
        <el-form-item label="书名">
          <el-input v-model="form.bookname" />
        </el-form-item>
        <el-form-item label="作者">
          <el-input v-model="form.authors" />
        </el-form-item>
        <el-form-item label="出版社">
          <el-input v-model="form.publication" />
        </el-form-item>
        <el-form-item label="出版日期">
          <el-date-picker v-model="form.publicdate" type="date" value-format="YYYY-MM-DD" />
        </el-form-item>
        <el-form-item label="价格">
          <el-input v-model="form.price" type="number" />
        </el-form-item>
      </el-form>
      <template #footer>
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="saveBook">保存</el-button>
      </template>
    </el-dialog>
  </div>
</template>

<script>
import { ref, onMounted } from 'vue'
import { ElMessage, ElMessageBox } from 'element-plus'
import { bookApi } from '../api'

export default {
  name: 'BookList',
  setup() {
    const books = ref([])
    const dialogVisible = ref(false)
    const dialogTitle = ref('添加图书')
    const isEdit = ref(false)
    const form = ref({
      bookid: '',
      bookname: '',
      authors: '',
      publication: '',
      publicdate: '',
      price: 0
    })

    const loadBooks = async () => {
      try {
        const response = await bookApi.getAll()
        books.value = response.data
      } catch (error) {
        ElMessage.error('加载图书列表失败')
      }
    }

    const showAddDialog = () => {
      dialogTitle.value = '添加图书'
      isEdit.value = false
      form.value = {
        bookid: '',
        bookname: '',
        authors: '',
        publication: '',
        publicdate: '',
        price: 0
      }
      dialogVisible.value = true
    }

    const editBook = (book) => {
      dialogTitle.value = '编辑图书'
      isEdit.value = true
      form.value = { ...book }
      dialogVisible.value = true
    }

    const saveBook = async () => {
      try {
        if (isEdit.value) {
          await bookApi.update(form.value.bookid, form.value)
          ElMessage.success('更新成功')
        } else {
          await bookApi.create(form.value)
          ElMessage.success('添加成功')
        }
        dialogVisible.value = false
        loadBooks()
      } catch (error) {
        ElMessage.error('保存失败')
      }
    }

    const deleteBook = (id) => {
      ElMessageBox.confirm('确定要删除这本图书吗?', '提示', {
        confirmButtonText: '确定',
        cancelButtonText: '取消',
        type: 'warning'
      }).then(async () => {
        try {
          await bookApi.delete(id)
          ElMessage.success('删除成功')
          loadBooks()
        } catch (error) {
          ElMessage.error('删除失败')
        }
      })
    }

    onMounted(() => {
      loadBooks()
    })

    return {
      books,
      dialogVisible,
      dialogTitle,
      isEdit,
      form,
      showAddDialog,
      editBook,
      saveBook,
      deleteBook
    }
  }
}
</script>

<style scoped>
.book-list {
  padding: 20px;
}
</style>
