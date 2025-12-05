<template>
  <div class="borrow-list">
    <h2>借阅管理</h2>
    <el-button type="primary" @click="showAddDialog">添加借阅记录</el-button>

    <el-table :data="borrows" style="width: 100%; margin-top: 20px" border>
      <el-table-column prop="userid" label="用户ID" width="120" />
      <el-table-column prop="bookid" label="图书ID" width="120" />
      <el-table-column prop="borrowtime" label="借阅时间" width="180" />
      <el-table-column prop="returntime" label="归还时间" width="180" />
      <el-table-column prop="penalsum" label="罚款金额" width="120" />
      <el-table-column prop="payment" label="已付金额" width="120" />
      <el-table-column label="操作" width="180">
        <template #default="{ row }">
          <el-button size="small" @click="editBorrow(row)">编辑</el-button>
          <el-button size="small" type="danger" @click="deleteBorrow(row.userid, row.bookid)">删除</el-button>
        </template>
      </el-table-column>
    </el-table>

    <el-dialog v-model="dialogVisible" :title="dialogTitle" width="500px">
      <el-form :model="form" label-width="100px">
        <el-form-item label="用户ID">
          <el-input v-model="form.userid" :disabled="isEdit" />
        </el-form-item>
        <el-form-item label="图书ID">
          <el-input v-model="form.bookid" :disabled="isEdit" />
        </el-form-item>
        <el-form-item label="借阅时间">
          <el-date-picker v-model="form.borrowtime" type="datetime" value-format="YYYY-MM-DD HH:mm:ss" />
        </el-form-item>
        <el-form-item label="归还时间">
          <el-date-picker v-model="form.returntime" type="datetime" value-format="YYYY-MM-DD HH:mm:ss" />
        </el-form-item>
        <el-form-item label="罚款金额">
          <el-input v-model="form.penalsum" type="number" />
        </el-form-item>
        <el-form-item label="已付金额">
          <el-input v-model="form.payment" type="number" />
        </el-form-item>
      </el-form>
      <template #footer>
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="saveBorrow">保存</el-button>
      </template>
    </el-dialog>
  </div>
</template>

<script>
import { ref, onMounted } from 'vue'
import { ElMessage, ElMessageBox } from 'element-plus'
import { borrowApi } from '../api'

export default {
  name: 'BorrowList',
  setup() {
    const borrows = ref([])
    const dialogVisible = ref(false)
    const dialogTitle = ref('添加借阅记录')
    const isEdit = ref(false)
    const form = ref({
      userid: '',
      bookid: '',
      borrowtime: '',
      returntime: '',
      penalsum: 0,
      payment: 0
    })

    const loadBorrows = async () => {
      try {
        const response = await borrowApi.getAll()
        borrows.value = response.data
      } catch (error) {
        ElMessage.error('加载借阅列表失败')
      }
    }

    const showAddDialog = () => {
      dialogTitle.value = '添加借阅记录'
      isEdit.value = false
      form.value = {
        userid: '',
        bookid: '',
        borrowtime: '',
        returntime: '',
        penalsum: 0,
        payment: 0
      }
      dialogVisible.value = true
    }

    const editBorrow = (borrow) => {
      dialogTitle.value = '编辑借阅记录'
      isEdit.value = true
      form.value = { ...borrow }
      dialogVisible.value = true
    }

    const saveBorrow = async () => {
      try {
        if (isEdit.value) {
          await borrowApi.update(form.value.userid, form.value.bookid, form.value)
          ElMessage.success('更新成功')
        } else {
          await borrowApi.create(form.value)
          ElMessage.success('添加成功')
        }
        dialogVisible.value = false
        loadBorrows()
      } catch (error) {
        ElMessage.error('保存失败')
      }
    }

    const deleteBorrow = (userid, bookid) => {
      ElMessageBox.confirm('确定要删除这条借阅记录吗?', '提示', {
        confirmButtonText: '确定',
        cancelButtonText: '取消',
        type: 'warning'
      }).then(async () => {
        try {
          await borrowApi.delete(userid, bookid)
          ElMessage.success('删除成功')
          loadBorrows()
        } catch (error) {
          ElMessage.error('删除失败')
        }
      })
    }

    onMounted(() => {
      loadBorrows()
    })

    return {
      borrows,
      dialogVisible,
      dialogTitle,
      isEdit,
      form,
      showAddDialog,
      editBorrow,
      saveBorrow,
      deleteBorrow
    }
  }
}
</script>

<style scoped>
.borrow-list {
  padding: 20px;
}
</style>
