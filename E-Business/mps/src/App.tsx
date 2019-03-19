import {Menu, Icon, Table,Button,Row,Col,InputNumber,DatePicker  } from 'antd';
import {
  BrowserRouter as Router,
  Link,Route
} from 'react-router-dom'
import * as React from 'react';
import './App.css';

function Inventory(props:any){
    return (
      <div>
      <Table columns={props.state.columns} dataSource={props.state.data} rowKey= "id" childrenColumnName="neededItem"></Table>
      <Button 
        type="primary" 
        onClick={props.onClick} >
      刷新
      </Button>
      </div>
    )
}

class App extends React.Component<{},{current:any,inventorydata:any,adddate:any,current_id:any,current_count:any,current_date:any}> {
  constructor(props:any){
    super(props)
    this.state = {
      current: 'mail',
      inventorydata:{
        columns: [
          {
          title: '编号',
          dataIndex: 'id',
          key: 'id',
          width: '6%'
        },{
          title: '货品',
          dataIndex: 'name',
          key: 'name',
        }, {
          title: '单位',
          dataIndex: 'unit',
          key: 'unit',
          width: '10%',
        },{
          title: '调配方式',
          dataIndex: 'method',
          key: 'method',
          width: '10%',
          render: (method : Boolean) =>(
            <div>{method?'生产' : '采购'}</div>
          )
        },{
          title: '损耗',
          dataIndex: 'loss',
          key: 'loss',
          width: '10%',
        }, {
          title: '作业提前期',
          dataIndex: 'workAhead',
          width: '10%',
          key: 'workAhead',
        }, {
          title: '工序库存',
          dataIndex: 'process_inv',
          key: 'process_inv',
          width: '10%',
        }, {
          title: '资材库存',
          dataIndex: 'material_inv',
          width: '10%',
          key: 'material_inv',
        }
        ],
        data: null
      },
      adddate:{
        columns:[
          {
            title:'编号',
            dataIndex:'material',
            render: (material:any) => `${material.id}`,
            key: 'id'
          },{
            title:'名称',
            dataIndex:'material',
            render:(material:any)=>`${material.name}`,
            key:'material.name'
          },{
            title:'需求数量',
            dataIndex:'newCount',
            key:'newCount'
          },{
            title: '下单时间',
            dataIndex: 'readyDate',
            key:'readyDate'
          },{
            title:'完成时间',
            dataIndex:'finishedDate',
            key:'finishedDate'
          }
        ],
        data:null
      },
      current_id:0,
      current_count:0,
      current_date: '123'
    }
  }


  fetchinventorydata() {
    fetch('http://127.0.0.1:8080/api/inventory',{
      method: 'GET',
      mode:'cors'
  })
    .then((response:any)=>response.json())
    .then((d:any)=>{

      this.setState({
        inventorydata: Object.assign({}, this.state.inventorydata, {data: d})
      }
      )
    })
  }

  addRecord() {
    
  }

  handleClick = (e:any) => {
    console.log('click ', e);
    this.setState({
      current: e.key,
    });
  }

  renderTable(){
    return(
      <Inventory state={this.state.inventorydata} onClick = {()=>this.fetchinventorydata()}></Inventory>
    )
  }

  onChange = (value:any)=>{
    this.setState({
      current_id:value
    })
  }
  onCountChange = (value:any)=>{
    this.setState({
      current_count:value
    })
  }
  onDateChange= (date:any, dateString:any)=> {
    console.log(date, dateString);
    this.setState({
      current_date:dateString
    })
  }
  getProductName = () =>{
    if(this.state.inventorydata.data==null) return ''
    if(this.state.current_id<=0||this.state.current_id>this.state.inventorydata.data.length) return ''
    return this.state.inventorydata.data[this.state.current_id-1].name
  }
  submit=()=>{
    let request={}
    request['id']=this.state.current_id;
    request['count']=this.state.current_count;
    request['date']=this.state.current_date;
    console.log(request)
    fetch('http://127.0.0.1:8080/api/addRecord',{
      method: 'POST',
      mode:'cors',
      headers: new Headers({
        'Content-Type': 'application/json'
      }),
      body:JSON.stringify(request)
  })
    .then((response:any)=>response.json())
    .then((d:any)=>{

      this.setState({
        adddate: Object.assign({}, this.state.adddate, {data: d})
      }
      )
    })
  }
  renderAdd(){
    return(
      <div>
      <Row>
      <Col span={6}>物品：<InputNumber onChange={this.onChange}></InputNumber>{this.getProductName()}</Col>
      <Col span={6}>数量：<InputNumber onChange={this.onCountChange}></InputNumber></Col>
      <Col span={6}>日期：<DatePicker onChange={this.onDateChange} /></Col>
      <Col span={6}><Button type="primary" onClick={this.submit}>提交</Button></Col>
    </Row>
      <Inventory state={this.state.adddate} onClick = {()=>this.addRecord()}></Inventory>
      </div>
    )
  }

  public render() {
    return (
      
      <Router>
      <div className="App">

      <Menu
        onClick={this.handleClick}
        selectedKeys={[this.state.current]}
        mode="horizontal"
      >
        <Menu.Item key="inventory">
        <Link to={'/inventory'} >
          <Icon type="mail" />库存</Link>
        </Menu.Item>
        <Menu.Item key="add"><Link to={'/add'}>
          <Icon type="appstore" />添加纪录</Link>
        </Menu.Item>
        
      </Menu>
      
      <Route path='/inventory' render={(props:any)=> (this.renderTable())}/>
      <Route path='/add' render={(props:any)=>(this.renderAdd())}/>
      </div>
      </Router>
      
    );
  }
}

export default App;