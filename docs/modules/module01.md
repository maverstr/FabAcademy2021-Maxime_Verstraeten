# 1. Project Management


## Tools for developing my Website


### MkDocs

### Atom

## Git

### Adding SSH authentication
In order to secure the connection, I used the **SSH protocol** that GitLab provides. This option allows to authenticate to the GitLab remote server without having to enter my login details every time I'm trying to push my work.


The SSH (or Secure Shell) protocol that uses _public-key (or asymmetric) cryptography_, meaning that with my public key (accessible to anyone I share it with, and I don't care who I share it with), everyone can encrypt a message that only me will be able to decrypt using my very secret very personal private key.

With my public key, GitLab can encrypt a message for me, that I can decrypt (as I have the corresponding private key) and I can send it back for verification. Since only me would be able to decrypt the message, GitLab can be sure that it is me on the other end of the communication, hence, I am authenticated.

#### How ?
First thing first, I need to generate my own pair of keys.

The _SSH-keygen_ is a tool that can create those kind of pairs and the OpenSSH client is natively pre-installed on many operating systems, including Win10.

Multiple types of encryptions exist, among these the most known RSA and the ED25519. The latter is suggested more secure (others are also deprecated like the DSA, as they present security issues) so we'll go on with ED25519 but the process is mostly the same for whatever type of keys.

###### Generating a new key pair

`ssh-keygen -t ed25519 -C "MyKeyName"`
created my pair of keys in the folder of my choice.
I then selected my public key and set it up on my GitLab settings.
It is also possible to use a passphrase to further encode the private key in case it gets divulgated.

###### Listing GitLab as a known host
When connecting to a new host, we first must verify that this host can be trusted.
`ssh -T git@gitlab.fabcloud.org`
We can also consult the SSH host keys fingerprints to further ensure that we are connecting to the host we want but I did not find those fingerprints for the FabAcademy GitLab instance.

Once done, we can use that command again and GitLab should be able to authenticate our identity.

With this, no need to log in for every push.
For increased security, SSH could also be used for 2FA (2-factor authentication).
