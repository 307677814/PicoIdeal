import Vue from "vue";
import VueRouter from "vue-router";
import { getToken } from "@/utils/auth";

Vue.use(VueRouter);

const routes = [
  {
    path: "/",
    component: () => import("@/views/layout"),
    redirect: "/index",
    children: [
      {
        path: "index",
        name: "index",
        component: () => import("@/views/index"),
        meta: {
          title: "首页",
          auth: true,
        },
      },
    ],
  },
  {
    path: "/system",
    component: () => import("@/views/layout"),
    redirect: "noRedirect",
    meta: {
      title: "系统管理",
    },
    children: [
      {
        path: "user",
        name: "user",
        component: () => import("@/views/user/index"),
        meta: {
          title: "用户管理",
          auth: true,
        },
      },
    ],
  },
  {
    path: "/product",
    component: () => import("@/views/layout"),
    redirect: "noRedirect",
    meta: {
      title: "产品管理",
    },
    children: [
      {
        path: "protocol",
        name: "protocol",
        component: () => import("@/views/protocol/index"),
        meta: {
          title: "协议管理",
          auth: true,
        },
      },
      {
        path: "device",
        name: "device",
        component: () => import("@/views/device/index"),
        meta: {
          title: "设备管理",
          auth: true,
        },
      },
      {
        path: "property/:protocolId(\\d+)",
        name: "property",
        component: () => import("@/views/property/index"),
        meta: {
          title: "属性管理",
          auth: true,
        },
      },
      {
        path: "data/:deviceSn(\\d+)",
        name: "data",
        component: () => import("@/views/data/index"),
        meta: {
          title: "设备数据",
          auth: true,
        },
      },
    ],
  },
  {
    path: "/login",
    name: "login",
    component: () => import("@/views/login"),
  },
  {
    path: "/register",
    name: "register",
    component: () => import("@/views/register"),
  },
  {
    path: "/404",
    component: () => import("@/views/error/404"),
  },
  {
    path: "*",
    redirect: "/404",
  },
];

const router = new VueRouter({
  mode: "history",
  base: process.env.BASE_URL,
  routes,
});

router.beforeEach((to, from, next) => {
  const token = getToken();
  if (token && to.path !== "/login") {
    // 有token 但不是去 login页面 通过
    next();
  } else if (token && to.path === "/login") {
    // 有token 但是去 login页面 不通过 重定向到首页
    next("/");
  } else if (!token && to.path !== "/login") {
    // 没有token 但不是去 login页面 不通过（未登录不给进入）
    next("/login");
  } else {
    // 剩下最后一种 没有token 但是去 login页面 通过
    next();
  }
});

export default router;
