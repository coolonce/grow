<template>
  <div class="sidebar">
    <div class="sidebar-inner">
      <div class="list">
        <ul class='menu-root'>
            <li v-for="device in devices" :key="device.id" id="device.id">
                {{device.name_owner}}
            </li>
        </ul>
      </div>
    </div>
  </div>
</template>
<script>
import axios from 'axios'
export default{
  name: 'device-list',
  data () {
    return {
      devices: []
    }
  },
  created () {
    const path = `http://localhost:5000/api/device`
    axios.get(path)
      .then(response => {
        console.log(response)
        this.devices = response.data
      })
      .catch(error => {
        console.log(error)
      })
  },
  mounted: function () {
    console.log('mounted')
  },
  methods: {
  }
}
</script>
