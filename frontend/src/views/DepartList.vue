<template>
  <div class="depart-list">
    <h2>部门管理</h2>
    <el-button type="primary" @click="showAddDialog">添加部门</el-button>

    <el-table :data="departs" style="width: 100%; margin-top: 20px" border>
      <el-table-column prop="departid" label="部门ID" width="120" />
      <el-table-column prop="departname" label="部门名称" width="200" />
      <el-table-column prop="parentdepartid" label="父部门ID" width="150" />
      <el-table-column label="操作" width="180">
        <template #default="{ row }">
          <el-button size="small" @click="editDepart(row)">编辑</el-button>
          <el-button size="small" type="danger" @click="deleteDepart(row.departid)">删除</el-button>
        </template>
      </el-table-column>
    </el-table>

    <el-dialog v-model="dialogVisible" :title="dialogTitle" width="500px">
      <el-form :model="form" label-width="100px">
        <el-form-item label="部门ID">
          <el-input v-model="form.departid" :disabled="isEdit" />
        </el-form-item>
        <el-form-item label="部门名称">
          <el-input v-model="form.departname" />
        </el-form-item>
        <el-form-item label="父部门ID">
          <el-input v-model="form.parentdepartid" />
        </el-form-item>
      </el-form>
      <template #footer>
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="saveDepart">保存</el-button>
      </template>
    </el-dialog>
  </div>
</template>

<script>
import { ref, onMounted } from 'vue'
import { ElMessage, ElMessageBox } from 'element-plus'
import { departApi } from '../api'

export default {
  name: 'DepartList',
  setup() {
    const departs = ref([])
    const dialogVisible = ref(false)
    const dialogTitle = ref('添加部门')
    const isEdit = ref(false)
    const form = ref({
      departid: '',
      departname: '',
      parentdepartid: ''
    })

    const loadDeparts = async () => {
      try {
        const response = await departApi.getAll()
        departs.value = response.data
      } catch (error) {
        ElMessage.error('加载部门列表失败')
      }
    }

    const showAddDialog = () => {
      dialogTitle.value = '添加部门'
      isEdit.value = false
      form.value = {
        departid: '',
        departname: '',
        parentdepartid: ''
      }
      dialogVisible.value = true
    }

    const editDepart = (depart) => {
      dialogTitle.value = '编辑部门'
      isEdit.value = true
      form.value = { ...depart }
      dialogVisible.value = true
    }

    const saveDepart = async () => {
      try {
        if (isEdit.value) {
          await departApi.update(form.value.departid, form.value)
          ElMessage.success('更新成功')
        } else {
          await departApi.create(form.value)
          ElMessage.success('添加成功')
        }
        dialogVisible.value = false
        loadDeparts()
      } catch (error) {
        ElMessage.error('保存失败')
      }
    }

    const deleteDepart = (id) => {
      ElMessageBox.confirm('确定要删除这个部门吗?', '提示', {
        confirmButtonText: '确定',
        cancelButtonText: '取消',
        type: 'warning'
      }).then(async () => {
        try {
          await departApi.delete(id)
          ElMessage.success('删除成功')
          loadDeparts()
        } catch (error) {
          ElMessage.error('删除失败')
        }
      })
    }

    onMounted(() => {
      loadDeparts()
    })

    return {
      departs,
      dialogVisible,
      dialogTitle,
      isEdit,
      form,
      showAddDialog,
      editDepart,
      saveDepart,
      deleteDepart
    }
  }
}
</script>

<style scoped>
.depart-list {
  padding: 20px;
}
</style>
