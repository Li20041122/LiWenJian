<template>
  <div id="app">
    <el-container style="height: 100vh">
      <el-header style="background-color: #409EFF; color: white; line-height: 60px">
        <h2 style="margin: 0">图书借阅管理系统</h2>
      </el-header>
      <el-container>
        <el-aside width="200px" style="background-color: #f0f0f0">
          <el-menu :default-active="$route.path" router>
            <el-menu-item index="/books">
              <span>图书管理</span>
            </el-menu-item>
            <el-menu-item index="/users">
              <span>用户管理</span>
            </el-menu-item>
            <el-menu-item index="/borrows">
              <span>借阅管理</span>
            </el-menu-item>
            <el-menu-item index="/departs">
              <span>部门管理</span>
            </el-menu-item>
          </el-menu>
        </el-aside>
        <el-main>
          <router-view />
        </el-main>
      </el-container>
    </el-container>
  </div>
</template>

<script>
export default {
  name: 'App'
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
}
body {
  margin: 0;
  padding: 0;
}
</style>
