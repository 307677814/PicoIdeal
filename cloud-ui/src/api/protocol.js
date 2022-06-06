import request from '@/utils/request'

// 查询协议列表
export function listProtocol(query) {
  return request({
    url: '/protocol/list',
    method: 'get',
    params: query
  })
}

// 查询协议详细
export function getProtocol(protocolId) {
  return request({
    url: '/protocol/' + protocolId,
    method: 'get'
  })
}

// 新增协议
export function addProtocol(data) {
  return request({
    url: '/protocol',
    method: 'post',
    data: data
  })
}

// 修改协议
export function updateProtocol(data) {
  return request({
    url: '/protocol',
    method: 'put',
    data: data
  })
}

// 删除协议
export function delProtocol(protocolId) {
  return request({
    url: '/protocol/' + protocolId,
    method: 'delete'
  })
}
