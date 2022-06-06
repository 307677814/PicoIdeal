import request from '@/utils/request'
import { parseStrEmpty } from "@/utils/picoIdeal";

// 查询设备列表
export function listDevice(query) {
  return request({
    url: '/device/list',
    method: 'get',
    params: query
  })
}

// 查询设备详细
export function getDevice(deviceId) {
  return request({
    url: '/device/' + parseStrEmpty(deviceId),
    method: 'get'
  })
}

// 新增设备
export function addDevice(data) {
  return request({
    url: '/device',
    method: 'post',
    data: data
  })
}

// 修改设备
export function updateDevice(data) {
  return request({
    url: '/device',
    method: 'put',
    data: data
  })
}

// 删除设备
export function delDevice(deviceSn) {
  return request({
    url: '/device/' + deviceSn,
    method: 'delete'
  })
}
