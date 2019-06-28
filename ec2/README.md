## how to setup Amazone EC2 
(_written by **Yilong**_)  
### How to create an account/log in

1. If you do not have an AWS account, please go to <a href="https://aws.amazon.com">AWS Webpage</a> to <b><i>Create an AWS Account</i></b>

![aws_homepage](https://user-images.githubusercontent.com/41296962/59551931-f27cd880-8f4e-11e9-981d-eb7b8eaaec76.png)

2. Fill in personal information: username, password, contact info, credit card info (credit card will be charged for 1 US dollar even through you choose a 1-year free account)

![aws_register](https://user-images.githubusercontent.com/41296962/59552124-ea259d00-8f50-11e9-9267-ab63c858ccca.png)

3. Enter the AWS Console, then choose <b><i>EC2</i></b>

![aws_overview](https://user-images.githubusercontent.com/41296962/59552150-2a851b00-8f51-11e9-8dfa-57569334df46.png)

4. Choose the nearest server location (before that, you can test the Ping speed on <a href="https://www.cloudping.info/">CloudPing</a>)

![aws_choose_location](https://user-images.githubusercontent.com/41296962/59552168-746e0100-8f51-11e9-9d7f-8cf87c791363.png)

![aws_ping](https://user-images.githubusercontent.com/41296962/59552173-7f289600-8f51-11e9-85ac-6c8c7c8cc4d5.png)

### Create Instance

1. Now you are in the EC2 page: click <b><i>Launch Instance</i></b>. You can use <b><i>Community AMIs</i></b> to filter, or can choose Amazon Linux AMI directly

![aws_choose_ami](https://user-images.githubusercontent.com/41296962/59552232-5b198480-8f52-11e9-963f-02d376d68e85.png)

2. Choose the type marked as <b><i>Free tier eligible</i></b>

![aws_choose_instance_type](https://user-images.githubusercontent.com/41296962/59552255-8e5c1380-8f52-11e9-9876-ad938def593b.png)

3. Follow the instructions to complete step by step, at last need to choose <b><i>Key Pair</i></b> after launching it. You can select <b><i>Choose an existing key pair</i></b>, als can choose to <b><i>Create a new key pair</i></b>. Then choose <b><i>Download Key Pair</i></b>.
You must download it as this is the only chance to store the private key pair file. Everytime you launch the instance, the private key will be asked.

![aws_select_key_pair](https://user-images.githubusercontent.com/41296962/59552347-aed89d80-8f53-11e9-8ee0-54374dacf9e9.png)

### Connect with the Server

1. using PuTTY
(1) Download the PuTTY software from <b><i><a href="www.putty.org">www.putty.org</a></i></b>. Be sure to download the entire package as shown below, as it will include all the needed utilities such as puttygen and pageant.
