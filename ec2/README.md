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
A key pair consists of a public key that AWS stores and a private key file that you store (downloaded as PEM file). Together, the two keys enable you to securely connect to your EC2 instance using SSH.
You must download it as this is the only chance to store the private key pair file. Everytime you launch the instance, the private key will be asked.

![aws_select_key_pair](https://user-images.githubusercontent.com/41296962/59552347-aed89d80-8f53-11e9-8ee0-54374dacf9e9.png)

### Connect to the Server

1. using PuTTY

1-1. Download the PuTTY software from <b><i><a href="https://www.putty.org/">www.putty.org</a></i></b>. Be sure to download the entire package as shown below, as it will include all the needed utilities such as puttygen and pageant.
<img width="950" alt="ec2_PuttyDownload" src="https://user-images.githubusercontent.com/41296962/60362758-bb2b1480-99af-11e9-9c32-fe8871e14415.png">

1-2. Now we need the key pair that is downloaded when creating the instance. Convert the PEM file to PPK format. 

  (1) Open the PuTTYgen software. You can find it in the PuTTY directory from Start Menu.
      On the PuTTYgen dialog box, click the Load Button and then select the .PEM file. Note: when browsing for the PEM file be sure to         select <b><i>All Files</i></b> in the dropdown list. PuTTYgen will then load and convert your file.
<img width="820" alt="ec2_PuttygenLoad" src="https://user-images.githubusercontent.com/41296962/60363700-35f52f00-99b2-11e9-9c6c-4c6208557c93.png">

![ec2_PuttygenConvert](https://user-images.githubusercontent.com/41296962/60363774-72c12600-99b2-11e9-8bde-fa1b90837478.png)

  (2) click on “Save private key”. A warning message asking if you want to save this key without a passphrase. Select Yes. Provide a           name for your ppk file and click save.
![ec2_PuttygenSave](https://user-images.githubusercontent.com/41296962/60363934-d1869f80-99b2-11e9-9633-babe15697be7.png)

Now the PEM file has been converted to a PPK file, it is ready to use the PuTTY utility. 

1-3. Launch PuTTY. 

  (1) Enter Host Name into the appropriate field. This will be in the format of: user_name@public_dns_name. For an Ubuntu AMI, the user       name is ubuntu or root. Or, use the IPv4 Public IP. 

![ec2_PuttyHostname](https://user-images.githubusercontent.com/41296962/60364559-7f467e00-99b4-11e9-93d6-e2f298ba906d.png)

  (2) Next, click on the <b><i>+</i></b> button next to the SSH field to expand this section. Then click on <b><i>Auth</i></b> and browse to search the private key file (the PPK file)

<img width="808" alt="ec2_PuttyPrivateKey" src="https://user-images.githubusercontent.com/41296962/60364827-29260a80-99b5-11e9-95de-881ce42808a4.png">

  (3) Lastly, click on Open to start your SSH session. If this is the first time to log into the instance, you will receive the               following alert. Click on Yes to continue.
  
  ![ec2_PuttyAlert](https://user-images.githubusercontent.com/41296962/60365016-b23d4180-99b5-11e9-9cba-156b6df6311a.png)

  (4) If everything is correct, you will see a new window appear displaying the command line SSH session. The default login name is           ubuntu.

<img width="495" alt="ec2_PuttyLoginAs" src="https://user-images.githubusercontent.com/41296962/60365221-1bbd5000-99b6-11e9-9b6b-a8ff507db3b8.png">
  
