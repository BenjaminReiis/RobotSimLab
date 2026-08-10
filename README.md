<p align="center">
  <img src="assets/banner.png" alt="Robot Sim Lab" width="100%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Unreal%20Engine-5-ff5fb0?style=for-the-badge&logo=unrealengine&logoColor=black" />
  <img src="https://img.shields.io/badge/React-TypeScript-00e5ff?style=for-the-badge&logo=react&logoColor=black" />
  <img src="https://img.shields.io/badge/Pixel%20Streaming-WebRTC-8f7bff?style=for-the-badge" />
  <img src="https://img.shields.io/badge/FastAPI-Backend-00ffc3?style=for-the-badge&logo=fastapi&logoColor=black" />
  <img src="https://img.shields.io/badge/status-concept%2Fdesign-ffd23f?style=for-the-badge" />
  <img src="https://img.shields.io/badge/license-MIT-b16fff?style=for-the-badge" />
</p>

<h1 align="center">🤖 Robot Sim Lab</h1>

<p align="center">
  <b>🇺🇸 <a href="#-english">English</a> &nbsp;|&nbsp; 🇧🇷 <a href="#-português">Português</a></b>
</p>

---

## 🇺🇸 English

### 📌 About

**Robot Sim Lab** is a browser-based **robotics digital laboratory**: a 3D
simulation platform where robots, sensors, environments and control
algorithms run inside **Unreal Engine 5**, streamed to the browser in
real time via **Pixel Streaming 2 (WebRTC)**, with a **React + TypeScript**
front end for interaction, mission design and telemetry visualization.

It's not just "a page that shows a 3D robot" — it's a full pipeline for
**building environments, configuring robots and sensors, selecting control
algorithms, running missions and analyzing the resulting telemetry**.

### 🧠 High-level concept

```
                    ROBOT SIM LAB
                         │
              ┌──────────┴──────────┐
              │                     │
         WEB PLATFORM          UNREAL ENGINE 5
              │                     │
       React / TypeScript      3D Simulation
              │                Physics / Robots
              │                Sensors
              │                AI / Control
              │                     │
              └──── Pixel Streaming ┘
                         │
                        WebRTC
                         │
                      Browser
```

The browser is the **interaction and visualization panel**. Unreal Engine
is the **authority of the simulation** — physics, robot state, sensors,
controller and mission all live there. The browser never runs the physics
itself; it only sends commands and receives video + telemetry.

<p align="center">
  <img src="assets/architecture.png" alt="Web ↔ Unreal architecture" width="100%">
</p>

### 🧩 What you can build with it

1. **3D Lab** — mobile robots, industrial arms, drones, humanoids, sensors,
   obstacles, terrain, platforms, cameras and custom lighting/environments.
2. **Robot control layer** — a common command interface (`State`, `Sensors`,
   `Actuators`, `Controller`, `Physics`, `Mission`) so `DifferentialDriveRobot`,
   `IndustrialArmRobot`, `DroneRobot` and `HumanoidRobot` can share the same
   platform without one robot type dictating the whole system.
3. **Algorithm training/testing** — pick a controller (PID, Pure Pursuit,
   LQR, MPC, or a custom one) and watch the closed loop
   `Target trajectory → Controller → Robot → Sensors → Feedback` in real time.
4. **Autonomous missions** — define waypoints, obstacle avoidance and
   collision detection, then run the mission inside the 3D environment.
5. **Live telemetry** — position, velocity, angular velocity, battery, CPU
   and control frequency, plus real-time charts.
6. **Sensor simulation** — LiDAR, Camera, Depth Camera, IMU, GPS, Ultrasonic,
   Wheel Encoder, Force/Torque and Proximity, all behind a standardized
   `SensorData GetSensorData()` API so the same algorithm works across robots.

### 📁 Proposed project structure

```
robot-sim-platform/
│
├── Unreal/
│   └── RobotSim/
│       │
│       ├── Config/
│       ├── Content/
│       │   ├── Robots/
│       │   ├── Environments/
│       │   ├── Sensors/
│       │   ├── Missions/
│       │   └── UI/
│       │
│       └── Source/
│           └── RobotSim/
│               ├── Core/
│               ├── Robots/
│               ├── Sensors/
│               ├── Control/
│               ├── Missions/
│               ├── Telemetry/
│               └── PixelStreaming/
│
├── web/
│   ├── src/
│   │   ├── components/
│   │   ├── panels/
│   │   ├── telemetry/
│   │   ├── missions/
│   │   ├── robots/
│   │   ├── store/
│   │   └── App.tsx
│   │
│   ├── package.json
│   └── vite.config.ts
│
├── infrastructure/
│   └── pixel-streaming/
│
├── docker/
├── docs/
│
├── README.md
└── docker-compose.yml
```

The web front end is kept **separate** from Unreal — matching how the
current Pixel Streaming ecosystem keeps frontend/infrastructure decoupled
and customizable.

### 🔌 Web ↔ Unreal communication

An explicit JSON message layer, decoupling the front end from the robot's
internal implementation:

```json
{
  "type": "robot.command",
  "robotId": "robot_01",
  "command": "set_velocity",
  "payload": { "linear": 1.5, "angular": 0.25 }
}
```

```json
{
  "type": "mission.start",
  "missionId": "warehouse_navigation"
}
```

Unreal replies with telemetry:

```json
{
  "type": "robot.telemetry",
  "robotId": "robot_01",
  "timestamp": 1723286400,
  "state": { "x": 12.42, "y": 8.17, "z": 0.0, "velocity": 2.31 }
}
```

Pixel Streaming 2 already provides mechanisms to receive input from the
remote peer and forward it into the UE application — exactly what this
command layer needs.

### 🛠️ Stack

| Layer | Technologies |
|---|---|
| 🎮 **3D / Simulation** | Unreal Engine 5 · C++ · Blueprints · Chaos Physics · Enhanced Input · Niagara · UMG · Pixel Streaming 2 |
| 🌐 **Web** | React · TypeScript · Vite · Tailwind · Zustand · Recharts |
| 📡 **Streaming** | Pixel Streaming 2 + WebRTC (external infra matching the Unreal version, per Epic's recommendation) |
| ⚙️ **Backend** | FastAPI · PostgreSQL · Redis · WebSocket (users, projects, missions, experiments) |
| 🐳 **Infrastructure** | Docker · Nginx · Pixel Streaming Infrastructure |

### 🚀 Suggested workflow

```
CREATE PROJECT
      ↓
CREATE ENVIRONMENT
      ↓
ADD ROBOT
      ↓
CONFIGURE SENSORS
      ↓
SELECT CONTROLLER
      ↓
CREATE MISSION
      ↓
RUN SIMULATION
      ↓
COLLECT TELEMETRY
      ↓
ANALYZE RESULTS
      ↓
EXPORT EXPERIMENT
```

This turns the project into a real **educational robotics platform**, not
just a viewer.

### 🗺️ Roadmap

- [ ] MVP: single robot + single environment + Pixel Streaming loop working end-to-end
- [ ] Controller library (PID, Pure Pursuit, LQR, MPC, custom plugin support)
- [ ] Mission editor (waypoints, obstacle avoidance, collision detection)
- [ ] Telemetry dashboard with historical experiment comparison
- [ ] Multi-robot support in the same environment
- [ ] Experiment export (CSV/JSON + video)

### 🤝 Contributing

This is currently a design/architecture proposal. Issues and PRs discussing
the architecture, module boundaries or implementation approach are welcome.

### 📄 License

MIT — see the `LICENSE` file for details.

---

## 🇧🇷 Português

### 📌 Sobre

**Robot Sim Lab** é um **laboratório digital de robótica** no navegador:
uma plataforma de simulação 3D onde robôs, sensores, ambientes e algoritmos
de controle rodam dentro do **Unreal Engine 5**, transmitidos ao navegador
em tempo real via **Pixel Streaming 2 (WebRTC)**, com um front-end em
**React + TypeScript** para interação, criação de missões e visualização
de telemetria.

Não é apenas "uma página que mostra um robô 3D" — é um pipeline completo
para **construir ambientes, configurar robôs e sensores, selecionar
algoritmos de controle, rodar missões e analisar a telemetria resultante**.

### 🧠 Conceito geral

```
                    ROBOT SIM LAB
                         │
              ┌──────────┴──────────┐
              │                     │
         WEB PLATFORM          UNREAL ENGINE 5
              │                     │
       React / TypeScript      Simulação 3D
              │                Física / Robôs
              │                Sensores
              │                IA / Controle
              │                     │
              └──── Pixel Streaming ┘
                         │
                        WebRTC
                         │
                    Navegador
```

O navegador é o **painel de interação e visualização**. O Unreal Engine é a
**autoridade da simulação** — física, estado do robô, sensores, controlador
e missão vivem lá. O navegador nunca roda a física principal; ele apenas
envia comandos e recebe vídeo + telemetria.

<p align="center">
  <img src="assets/architecture.png" alt="Arquitetura Web ↔ Unreal" width="100%">
</p>

### 🧩 O que dá pra construir

1. **Laboratório 3D** — robôs móveis, braços industriais, drones, humanoides,
   sensores, obstáculos, terreno, plataformas, câmeras e iluminação/ambientes
   customizados.
2. **Camada de controle de robôs** — uma interface de comando comum (`State`,
   `Sensors`, `Actuators`, `Controller`, `Physics`, `Mission`), permitindo que
   `DifferentialDriveRobot`, `IndustrialArmRobot`, `DroneRobot` e
   `HumanoidRobot` compartilhem a mesma plataforma sem que um único tipo de
   robô dite o sistema inteiro.
3. **Treinamento/teste de algoritmos** — escolha um controlador (PID, Pure
   Pursuit, LQR, MPC ou customizado) e acompanhe o loop fechado
   `Target trajectory → Controller → Robot → Sensors → Feedback` em tempo real.
4. **Missões autônomas** — defina waypoints, obstacle avoidance e collision
   detection, e execute a missão dentro do ambiente 3D.
5. **Telemetria ao vivo** — posição, velocidade, velocidade angular, bateria,
   CPU e frequência de controle, além de gráficos em tempo real.
6. **Simulação de sensores** — LiDAR, Camera, Depth Camera, IMU, GPS,
   Ultrasonic, Wheel Encoder, Force/Torque e Proximity, todos atrás de uma
   API padronizada `SensorData GetSensorData()`, permitindo conectar o mesmo
   algoritmo a diferentes robôs.

### 📁 Estrutura proposta do projeto

```
robot-sim-platform/
│
├── Unreal/
│   └── RobotSim/
│       │
│       ├── Config/
│       ├── Content/
│       │   ├── Robots/
│       │   ├── Environments/
│       │   ├── Sensors/
│       │   ├── Missions/
│       │   └── UI/
│       │
│       └── Source/
│           └── RobotSim/
│               ├── Core/
│               ├── Robots/
│               ├── Sensors/
│               ├── Control/
│               ├── Missions/
│               ├── Telemetry/
│               └── PixelStreaming/
│
├── web/
│   ├── src/
│   │   ├── components/
│   │   ├── panels/
│   │   ├── telemetry/
│   │   ├── missions/
│   │   ├── robots/
│   │   ├── store/
│   │   └── App.tsx
│   │
│   ├── package.json
│   └── vite.config.ts
│
├── infrastructure/
│   └── pixel-streaming/
│
├── docker/
├── docs/
│
├── README.md
└── docker-compose.yml
```

O front-end web fica **separado** do Unreal — seguindo como o próprio
ecossistema atual do Pixel Streaming mantém frontend/infraestrutura
desacoplados e personalizáveis.

### 🔌 Comunicação Web ↔ Unreal

Uma camada explícita de mensagens JSON, desacoplando o front-end da
implementação interna do robô:

```json
{
  "type": "robot.command",
  "robotId": "robot_01",
  "command": "set_velocity",
  "payload": { "linear": 1.5, "angular": 0.25 }
}
```

```json
{
  "type": "mission.start",
  "missionId": "warehouse_navigation"
}
```

O Unreal responde com telemetria:

```json
{
  "type": "robot.telemetry",
  "robotId": "robot_01",
  "timestamp": 1723286400,
  "state": { "x": 12.42, "y": 8.17, "z": 0.0, "velocity": 2.31 }
}
```

O Pixel Streaming 2 já possui mecanismos para receber entrada do peer
remoto e repassá-la para a aplicação UE — exatamente o que essa camada de
comandos precisa.

### 🛠️ Stack

| Camada | Tecnologias |
|---|---|
| 🎮 **3D / Simulação** | Unreal Engine 5 · C++ · Blueprints · Chaos Physics · Enhanced Input · Niagara · UMG · Pixel Streaming 2 |
| 🌐 **Web** | React · TypeScript · Vite · Tailwind · Zustand · Recharts |
| 📡 **Streaming** | Pixel Streaming 2 + WebRTC (infraestrutura externa correspondente à versão do Unreal, conforme recomendação da Epic) |
| ⚙️ **Backend** | FastAPI · PostgreSQL · Redis · WebSocket (usuários, projetos, missões, experimentos) |
| 🐳 **Infraestrutura** | Docker · Nginx · Pixel Streaming Infrastructure |

### 🚀 Fluxo de trabalho sugerido

```
CREATE PROJECT
      ↓
CREATE ENVIRONMENT
      ↓
ADD ROBOT
      ↓
CONFIGURE SENSORS
      ↓
SELECT CONTROLLER
      ↓
CREATE MISSION
      ↓
RUN SIMULATION
      ↓
COLLECT TELEMETRY
      ↓
ANALYZE RESULTS
      ↓
EXPORT EXPERIMENT
```

Isso transforma o projeto numa verdadeira **plataforma educacional de
robótica**, e não só um visualizador.

### 🗺️ Roadmap

- [ ] MVP: um robô + um ambiente + loop de Pixel Streaming funcionando ponta a ponta
- [ ] Biblioteca de controladores (PID, Pure Pursuit, LQR, MPC, suporte a plugin customizado)
- [ ] Editor de missões (waypoints, obstacle avoidance, collision detection)
- [ ] Dashboard de telemetria com comparação histórica de experimentos
- [ ] Suporte a múltiplos robôs no mesmo ambiente
- [ ] Exportação de experimentos (CSV/JSON + vídeo)

### 🤝 Contribuindo

Este é, por enquanto, uma proposta de arquitetura/design. Issues e PRs
discutindo a arquitetura, os limites entre módulos ou a abordagem de
implementação são bem-vindos.

### 📄 Licença

MIT — veja o arquivo `LICENSE` para mais detalhes.

---

<p align="center">
  <sub>Unreal Engine 5 🎮 · React + TypeScript 🌐 · Pixel Streaming / WebRTC 📡 · FastAPI ⚙️</sub>
</p>
