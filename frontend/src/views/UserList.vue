<template>
  <div class="user-list">
    <h2>用户管理</h2>
    <el-button type="primary" @click="showAddDialog">添加用户</el-button>

    <el-table :data="users" style="width: 100%; margin-top: 20px" border>
      <el-table-column prop="userid" label="用户ID" width="120" />
      <el-table-column prop="username" label="用户名" width="150" />
      <el-table-column prop="departid" label="部门ID" width="120" />
      <el-table-column prop="phonenum" label="手机号" width="150" />
      <el-table-column prop="sex" label="性别" width="100" />
      <el-table-column label="操作" width="180">
        <template #default="{ row }">
          <el-button size="small" @click="editUser(row)">编辑</el-button>
          <el-button size="small" type="danger" @click="deleteUser(row.userid)">删除</el-button>
        </template>
      </el-table-column>
    </el-table>

    <el-dialog v-model="dialogVisible" :title="dialogTitle" width="500px">
      <el-form :model="form" label-width="100px">
        <el-form-item label="用户ID">
          <el-input v-model="form.userid" :disabled="isEdit" />
        </el-form-item>
        <el-form-item label="用户名">
          <el-input v-model="form.username" />
        </el-form-item>
        <el-form-item label="密码">
          <el-input v-model="form.password" type="password" />
        </el-form-item>
        <el-form-item label="部门ID">
          <el-input v-model="form.departid" />
        </el-form-item>
        <el-form-item label="手机号">
          <el-input v-model="form.phonenum" />
        </el-form-item>
        <el-form-item label="性别">
          <el-select v-model="form.sex" placeholder="请选择性别">
            <el-option label="男" value="男" />
            <el-option label="女" value="女" />
          </el-select>
        </el-form-item>
      </el-form>
      <template #footer>
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="saveUser">保存</el-button>
      </template>
    </el-dialog>
  </div>
</template>

<script>
import { ref, onMounted } from 'vue'
import { ElMessage, ElMessageBox } from 'element-plus'
import { userApi } from '../api'

export default {
  name: 'UserList',
  setup() {
    const users = ref([])
    const dialogVisible = ref(false)
    const dialogTitle = ref('添加用户')
    const isEdit = ref(false)
    const form = ref({
      userid: '',
      username: '',
      password: '',
      departid: '',
      phonenum: '',
      sex: ''
    })

    const loadUsers = async () => {
      try {
        const response = await userApi.getAll()
        users.value = response.data
      } catch (error) {
        ElMessage.error('加载用户列表失败')
      }
    }

    const showAddDialog = () => {
      dialogTitle.value = '添加用户'
      isEdit.value = false
      form.value = {
        userid: '',
        username: '',
        password: '',
        departid: '',
        phonenum: '',
        sex: ''
      }
      dialogVisible.value = true
    }

    const editUser = (user) => {
      dialogTitle.value = '编辑用户'
      isEdit.value = true
      form.value = { ...user }
      dialogVisible.value = true
    }

    const saveUser = async () => {
      try {
        if (isEdit.value) {
          await userApi.update(form.value.userid, form.value)
          ElMessage.success('更新成功')
        } else {
          await userApi.create(form.value)
          ElMessage.success('添加成功')
        }
        dialogVisible.value = false
        loadUsers()
      } catch (error) {
        ElMessage.error('保存失败')
      }
    }

    const deleteUser = (id) => {
      ElMessageBox.confirm('确定要删除这个用户吗?', '提示', {
        confirmButtonText: '确定',
        cancelButtonText: '取消',
        type: 'warning'
      }).then(async () => {
        try {
          await userApi.delete(id)
          ElMessage.success('删除成功')
          loadUsers()
        } catch (error) {
          ElMessage.error('删除失败')
        }
      })
    }

    onMounted(() => {
      loadUsers()
    })

    return {
      users,
      dialogVisible,
      dialogTitle,
      isEdit,
      form,
      showAddDialog,
      editUser,
      saveUser,
      deleteUser
    }
  }
}
</script>

<style scoped>
.user-list {
  padding: 20px;
}
</style>
